import { paginate, resolver, Ctx } from "blitz"
import db, { Prisma } from "db"

interface GetQuestionsInput
  extends Pick<Prisma.QuestionFindManyArgs, "where" | "orderBy" | "skip" | "take"> {}

export default resolver.pipe(
  resolver.authorize(),
  async ({ where, orderBy, skip = 0, take = 100 }: GetQuestionsInput, ctx: Ctx) => {
    // TODO: in multi-tenant app, you must add validation to ensure correct tenant
    const {
      items: questions,
      hasMore,
      nextPage,
      count,
    } = await paginate({
      skip,
      take,
      count: () => db.question.count({ where }),
      query: (paginateArgs) => db.question.findMany({ ...paginateArgs, where, orderBy, include: {choices: true} }),
    })

    return {
      questions,
      nextPage,
      hasMore,
      count,
      ctxSessionReq: Object.keys(ctx.session._req),
      ctxSessionRes: Object.keys(ctx.session._res),
      ctxSessionKernel: Object.keys(ctx.session._kernel),
      ctxSessionUserId: ctx.session.userId,
      ctxSessionCreate: typeof ctx.session.$create,
    }
  }
)
