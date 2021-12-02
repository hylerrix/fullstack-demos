import { sessionMiddleware, simpleRolesIsAuthorized } from "blitz"

module.exports = {
  middleware: [
    sessionMiddleware({
      cookiePrefix: 'doc-demo-0dot35',
      sessionExpiryMinutes: 1234,
      isAuthorized: simpleRolesIsAuthorized,
    }),
  ],
  async redirects() {
    return [
      {
        source: "/redirects",
        destination: "/",
        permanent: true,
      }
    ]
  },
  async rewrites() {
    return [
      {
        source: "/rewrites",
        destination: "/",
      }
    ]
  },
  async headers() {
    return [
      {
        source: '/headers',
        headers: [
          {
            key: "x-custom-header",
            value: "my custom header value",
          },
        ],
      },
    ]
  },
  /* Uncomment this to customize the webpack config
  webpack: (config, { buildId, dev, isServer, defaultLoaders, webpack }) => {
    // Note: we provide webpack above so you should not `require` it
    // Perform customizations to webpack config
    // Important: return the modified config
    return config
  },
  */
}
